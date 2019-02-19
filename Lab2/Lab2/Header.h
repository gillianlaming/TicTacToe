#pragma once

int messageFunct(const char * a);

int fileFailure();
enum inputs { programName, inputFile, commandLineArguments };

enum results { success, commandLineFail, unableToOpenFileFailure, cannotExtractDemensions, inputFileWrongSize, wrongBoardDimensions, cannotReadLine, badColor, unableToExtract, cantReadPieces}; //specify each failure

