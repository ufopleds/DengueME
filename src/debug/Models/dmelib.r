dmelib_check_dependencies <- function(modelRVersion = "", modelDependences = NULL, userRVersion = "", userLibs = NULL) {

   # checking R version
   cat("Checking compatibility of R version... ")
   if ((modelRVersion == userRVersion))
      cat(paste0("R version: ", userRVersion, ". OK!\n"))
   else
      warning(paste0("The R version in which the model was developed (", modelRVersion, ") is different from that you are using (", userRVersion, ")"))
   
   cat("Checking package dependencies... ")
   if (is.null(modelDependences) | nrow(modelDependences) == 0)
      cat("The model has no dependence on additional packages. OK!\n")
   else {
      
      listOfDependencies <- modelDependences$lib
      
      if (length(listOfDependencies) > 0) {
      
         # checking the version of packages installed by user and required by model
         outDateMsg <- "The following installed dependencies (packages) has a different version from that used by model\n"
         installedPackages <- userLibs[userLibs[,c("Package")] %in% listOfDependencies, c("Package", "Version")]
         
         if (is.matrix(installedPackages) & length(installedPackages) > 0) {
            for(i in 1:nrow(installedPackages))
               if (installedPackages[i,2] != modelDependences[which(modelDependences$lib == installedPackages[i,1]),2])
                  outDateMsg <- paste0(outDateMsg, "\t", installedPackages[i, "Package"], ": ", installedPackages[i,2], "(installed) - ", modelDependences[which(modelDependences$lib == installedPackages[i,1]),2], "(used by model)\n")
            warning(outDateMsg)
         } else if (is.character(installedPackages) & length(installedPackages) > 0) {
            if (installedPackages[2] != modelDependences[which(modelDependences$lib == installedPackages[1]),2])
               outDateMsg <- paste0(outDateMsg, "\t", installedPackages["Package"], ": ", installedPackages["Version"], "(installed) - ", modelDependences[which(modelDependences$lib == installedPackages[1]),2], "(used by model)\n")
            warning(outDateMsg)
         } 
         
         # checking the uninstalled packages required by model
         uninstalledPackages <- listOfDependencies[!(listOfDependencies %in% userLibs[,"Package"])]
         if (length(uninstalledPackages)) {
            warning(paste0("The following dependencies (packages) are not installed: ", paste(uninstalledPackages, collapse=", ")))
            
            for(i in 1:length(uninstalledPackages))
               install.packages(uninstalledPackages[i], dependencies = TRUE)
         }
         
      }
   }
   
}