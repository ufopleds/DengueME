#ifndef LEPTON_OPERATION_H_
#define LEPTON_OPERATION_H_

/* -------------------------------------------------------------------------- *
 *                                   Lepton                                   *
 * -------------------------------------------------------------------------- *
 * This is part of the Lepton expression parser originating from              *
 * Simbios, the NIH National Center for Physics-Based Simulation of           *
 * Biological Structures at Stanford, funded under the NIH Roadmap for        *
 * Medical Research, grant U54 GM072970. See https://simtk.org.               *
 *                                                                            *
 * Portions copyright (c) 2009-2013 Stanford University and the Authors.      *
 * Authors: Peter Eastman                                                     *
 * Contributors:                                                              *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining a    *
 * copy of this software and associated documentation files (the "Software"), *
 * to deal in the Software without restriction, including without limitation  *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,   *
 * and/or sell copies of the Software, and to permit persons to whom the      *
 * Software is furnished to do so, subject to the following conditions:       *
 *                                                                            *
 * The above copyright notice and this permission notice shall be included in *
 * all copies or substantial portions of the Software.                        *
 *                                                                            *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
 * THE AUTHORS, CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,    *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR      *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  *
 * USE OR OTHER DEALINGS IN THE SOFTWARE.                                     *
 * -------------------------------------------------------------------------- */

#include "windowsIncludes.h"
#include "CustomFunction.h"
#include "Exception.h"
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace Lepton {

class ExpressionTreeNode;

/**
 * An Operation represents a single step in the evaluation of an expression, such as a function,
 * an operator, or a constant value.  Each Operation takes some number of values as arguments
 * and produces a single value.
 *
 * This is an abstract class with subclasses for specific operations.
 */

class LEPTON_EXPORT Operation {
 public:
  virtual ~Operation() {
  }
  enum Id {CONSTANT, VARIABLE, CUSTOM, ADD, SUBTRACT, MULTIPLY, DIVIDE, POWER, NEGATE, SQUARE, CUBE, EXP,
           ADD_CONSTANT, MULTIPLY_CONSTANT, POWER_CONSTANT
          };

  virtual std::string getName() const = 0;

  virtual Id getId() const = 0;

  virtual int getNumArguments() const = 0;

  virtual Operation* clone() const = 0;

  virtual double evaluate(double* args  ) const = 0;

  virtual ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const = 0;
  virtual bool isInfixOperator() const {
    return false;
  }
  virtual bool isSymmetric() const {
    return false;
  }
  virtual bool operator!=(const Operation& op) const {
    return op.getId() != getId();
  }
  virtual bool operator==(const Operation& op) const {
    return !(*this != op);
  }
  class Constant;
  class Variable;
  class Custom;
  class Add;
  class Subtract;
  class Multiply;
  class Divide;
  class Power;
  class Negate;
  class Exp;
  class Fact;
  class Log;
  class Sin;
  class Cos;
  class Sec;
  class Csc;
  class Tan;
  class Cot;
  class Asin;
  class Acos;
  class Atan;
  class Sinh;
  class Cosh;
  class Tanh;
  class Erf;
  class Erfc;
  class Step;
  class Delta;
  class Square;
  class Cube;
  class Reciprocal;
  class AddConstant;
  class MultiplyConstant;
  class PowerConstant;
  class Min;
  class Max;
  class Abs;
};

class LEPTON_EXPORT Operation::Constant : public Operation {
 public:
  Constant(double value) : value(value) {
  }
  std::string getName() const {
    std::stringstream name;
    name << value;
    return name.str();
  }
  Id getId() const {
    return CONSTANT;
  }
  int getNumArguments() const {
    return 0;
  }
  Operation* clone() const {
    return new Constant(value);
  }
  double evaluate(double* args) const {
    args = args;
    return value;
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  double getValue() const {
    return value;
  }
  bool operator!=(const Operation& op) const {
    const Constant* o = dynamic_cast<const Constant*>(&op);
    return (o == NULL || o->value != value);
  }
 private:
  double value;
};

class LEPTON_EXPORT Operation::Variable : public Operation {
 public:
  Variable(const std::string& name) : name(name) {
  }
  std::string getName() const {
    return name;
  }
  Id getId() const {
    return VARIABLE;
  }
  int getNumArguments() const {
    return 0;
  }
  Operation* clone() const {
    return new Variable(name);
  }
  double evaluate(double* args  ) const {
    return args[0];

  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  bool operator!=(const Operation& op) const {
    const Variable* o = dynamic_cast<const Variable*>(&op);
    return (o == NULL || o->name != name);
  }
 private:
  std::string name;
};

class LEPTON_EXPORT Operation::Custom : public Operation {
 public:
  Custom(const std::string& name, CustomFunction* function) : name(name), function(function), isDerivative(false), derivOrder(function->getNumArguments(), 0) {
  }
  Custom(const Custom& base, int derivIndex) : name(base.name), function(base.function->clone()), isDerivative(true), derivOrder(base.derivOrder) {
    derivOrder[derivIndex]++;
  }
  ~Custom() {
    delete function;
  }
  std::string getName() const {
    return name;
  }
  Id getId() const {
    return CUSTOM;
  }
  int getNumArguments() const {
    return function->getNumArguments();
  }
  Operation* clone() const {
    Custom* clone = new Custom(name, function->clone());
    clone->isDerivative = isDerivative;
    clone->derivOrder = derivOrder;
    return clone;
  }
  double evaluate(double* args  ) const {
    if (isDerivative)
      return function->evaluateDerivative(args, &derivOrder[0]);
    return function->evaluate(args);
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  const std::vector<int>& getDerivOrder() const {
    return derivOrder;
  }
  bool operator!=(const Operation& op) const {
    const Custom* o = dynamic_cast<const Custom*>(&op);
    return (o == NULL || o->name != name || o->isDerivative != isDerivative || o->derivOrder != derivOrder);
  }
 private:
  std::string name;
  CustomFunction* function;
  bool isDerivative;
  std::vector<int> derivOrder;
};

class LEPTON_EXPORT Operation::Add : public Operation {
 public:
  Add() {
  }
  std::string getName() const {
    return "+";
  }
  Id getId() const {
    return ADD;
  }
  int getNumArguments() const {
    return 2;
  }
  Operation* clone() const {
    return new Add();
  }
  double evaluate(double* args  ) const {
    return args[0] + args[1];
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  bool isInfixOperator() const {
    return true;
  }
  bool isSymmetric() const {
    return true;
  }
};

class LEPTON_EXPORT Operation::Subtract : public Operation {
 public:
  Subtract() {
  }
  std::string getName() const {
    return "-";
  }
  Id getId() const {
    return SUBTRACT;
  }
  int getNumArguments() const {
    return 2;
  }
  Operation* clone() const {
    return new Subtract();
  }
  double evaluate(double* args  ) const {
    return args[0] - args[1];
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  bool isInfixOperator() const {
    return true;
  }
};

class LEPTON_EXPORT Operation::Multiply : public Operation {
 public:
  Multiply() {
  }
  std::string getName() const {
    return "*";
  }
  Id getId() const {
    return MULTIPLY;
  }
  int getNumArguments() const {
    return 2;
  }
  Operation* clone() const {
    return new Multiply();
  }
  double evaluate(double* args  ) const {
    return args[0] * args[1];
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  bool isInfixOperator() const {
    return true;
  }
  bool isSymmetric() const {
    return true;
  }
};

class LEPTON_EXPORT Operation::Divide : public Operation {
 public:
  Divide() {
  }
  std::string getName() const {
    return "/";
  }
  Id getId() const {
    return DIVIDE;
  }
  int getNumArguments() const {
    return 2;
  }
  Operation* clone() const {
    return new Divide();
  }
  double evaluate(double* args  ) const {
    return args[0] / args[1];
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  bool isInfixOperator() const {
    return true;
  }
};

class LEPTON_EXPORT Operation::Power : public Operation {
 public:
  Power() {
  }
  std::string getName() const {
    return "^";
  }
  Id getId() const {
    return POWER;
  }
  int getNumArguments() const {
    return 2;
  }
  Operation* clone() const {
    return new Power();
  }
  double evaluate(double* args  ) const {
    return std::pow(args[0], args[1]);
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  bool isInfixOperator() const {
    return true;
  }
};

class LEPTON_EXPORT Operation::Negate : public Operation {
 public:
  Negate() {
  }
  std::string getName() const {
    return "-";
  }
  Id getId() const {
    return NEGATE;
  }
  int getNumArguments() const {
    return 1;
  }
  Operation* clone() const {
    return new Negate();
  }
  double evaluate(double* args  ) const {
    return -args[0];
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
};


class LEPTON_EXPORT Operation::Exp : public Operation {
 public:
  Exp() {
  }
  std::string getName() const {
    return "exp";
  }
  Id getId() const {
    return EXP;
  }
  int getNumArguments() const {
    return 1;
  }
  Operation* clone() const {
    return new Exp();
  }
  double evaluate(double* args  ) const {
    return std::exp(args[0]);
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
};



class LEPTON_EXPORT Operation::Square : public Operation {
 public:
  Square() {
  }
  std::string getName() const {
    return "square";
  }
  Id getId() const {
    return SQUARE;
  }
  int getNumArguments() const {
    return 1;
  }
  Operation* clone() const {
    return new Square();
  }
  double evaluate(double* args  ) const {
    return args[0] * args[0];
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
};

class LEPTON_EXPORT Operation::Cube : public Operation {
 public:
  Cube() {
  }
  std::string getName() const {
    return "cube";
  }
  Id getId() const {
    return CUBE;
  }
  int getNumArguments() const {
    return 1;
  }
  Operation* clone() const {
    return new Cube();
  }
  double evaluate(double* args  ) const {
    return args[0] * args[0] * args[0];
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
};


class LEPTON_EXPORT Operation::AddConstant : public Operation {
 public:
  AddConstant(double value) : value(value) {
  }
  std::string getName() const {
    std::stringstream name;
    name << value << "+";
    return name.str();
  }
  Id getId() const {
    return ADD_CONSTANT;
  }
  int getNumArguments() const {
    return 1;
  }
  Operation* clone() const {
    return new AddConstant(value);
  }
  double evaluate(double* args  ) const {
    return args[0] + value;
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  double getValue() const {
    return value;
  }
  bool operator!=(const Operation& op) const {
    const AddConstant* o = dynamic_cast<const AddConstant*>(&op);
    return (o == NULL || o->value != value);
  }
 private:
  double value;
};

class LEPTON_EXPORT Operation::MultiplyConstant : public Operation {
 public:
  MultiplyConstant(double value) : value(value) {
  }
  std::string getName() const {
    std::stringstream name;
    name << value << "*";
    return name.str();
  }
  Id getId() const {
    return MULTIPLY_CONSTANT;
  }
  int getNumArguments() const {
    return 1;
  }
  Operation* clone() const {
    return new MultiplyConstant(value);
  }
  double evaluate(double* args  ) const {
    return args[0] * value;
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  double getValue() const {
    return value;
  }
  bool operator!=(const Operation& op) const {
    const MultiplyConstant* o = dynamic_cast<const MultiplyConstant*>(&op);
    return (o == NULL || o->value != value);
  }
 private:
  double value;
};

class LEPTON_EXPORT Operation::PowerConstant : public Operation {
 public:
  PowerConstant(double value) : value(value) {
    intValue = (int) value;
    isIntPower = (intValue == value);
  }
  std::string getName() const {
    std::stringstream name;
    name << "^" << value;
    return name.str();
  }
  Id getId() const {
    return POWER_CONSTANT;
  }
  int getNumArguments() const {
    return 1;
  }
  Operation* clone() const {
    return new PowerConstant(value);
  }
  double evaluate(double* args  ) const {
    if (isIntPower) {
      // Integer powers can be computed much more quickly by repeated multiplication.

      int exponent = intValue;
      double base = args[0];
      if (exponent < 0) {
        exponent = -exponent;
        base = 1.0 / base;
      }
      double result = 1.0;
      while (exponent != 0) {
        if ((exponent & 1) == 1)
          result *= base;
        base *= base;
        exponent = exponent >> 1;
      }
      return result;
    } else
      return std::pow(args[0], value);
  }
  ExpressionTreeNode differentiate(const std::vector<ExpressionTreeNode>& children, const std::vector<ExpressionTreeNode>& childDerivs  ) const;
  double getValue() const {
    return value;
  }
  bool operator!=(const Operation& op) const {
    const PowerConstant* o = dynamic_cast<const PowerConstant*>(&op);
    return (o == NULL || o->value != value);
  }
  bool isInfixOperator() const {
    return true;
  }
 private:
  double value;
  int intValue;
  bool isIntPower;
};

} // namespace Lepton

#endif /*LEPTON_OPERATION_H_*/
