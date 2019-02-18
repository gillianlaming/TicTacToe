#pragma once

enum inputs { programName, inputFile, commandLineArguments };

enum results { success, commandLineFail, unableToOpenFileFailure, cannotExtractDemensions, inputFileWrongSize}; //specify each failure

