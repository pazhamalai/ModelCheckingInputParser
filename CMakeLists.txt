cmake_minimum_required(VERSION 3.19)
project(ModelCheckingInputParser C)

set(CMAKE_C_STANDARD 99)

add_library(ModelCheckingInputParser MCIP.c MCIP.h VariablesParser/variablesReader.c VariablesParser/variablesReader.h FileReaderUtils/fileReaderUtils.c FileReaderUtils/fileReaderUtils.h FormulaParser/FormulaParser.c FormulaParser/FormulaParser.h FileReaderUtils/typeFinder.c FileReaderUtils/typeFinder.h commonUtils.c commonUtils.h)