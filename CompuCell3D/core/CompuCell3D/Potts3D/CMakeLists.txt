SET(SRCS
  AttributeAdder.cpp
  Cell.cpp
  CellInventory.cpp
  DefaultAcceptanceFunction.cpp
  EnergyFunctionCalculator.cpp
  EnergyFunctionCalculatorStatistics.cpp
  TypeTransition.cpp
  StandardFluctuationAmplitudeFunctions.cpp
  Potts3D.cpp)

INCLUDE_DIRECTORIES ( 
    ${COMPUCELL3D_SOURCE_DIR}/core
    )

if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

  ADD_STATIC_LIBRARY(Potts3D ${SRCS} LINK_LIBRARIES BasicUtilsStatic
  BoundaryShared
  Field3DStatic PublicUtilitiesStatic UnitsStatic EXTRA_COMPILER_FLAGS ${OpenMP_CXX_FLAGS})

else(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

  ADD_SHARED_LIBRARY(Potts3D ${SRCS} 
  LINK_LIBRARIES 
  gomp BoundaryShared BasicUtilsShared Field3DShared PublicUtilitiesShared UnitsShared 
  EXTRA_COMPILER_FLAGS 
  ${OpenMP_CXX_FLAGS})

endif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

INSTALL_FILES(/include/CompuCell3D/CompuCell3D/Potts3D .h
  AcceptanceFunction
  AttributeAdder
  CellChangeWatcher
  CellGChangeWatcher
  Cell
  CellInventory
  CellTypeMotilityData
  DefaultAcceptanceFunction
  EnergyFunction
  EnergyFunctionCalculator
  EnergyFunctionCalculatorStatistics
  FirstOrderExpansionAcceptanceFunction
  FixedStepper
  Potts3D
  Stepper
  TypeChangeWatcher
  TypeTransition
  FluctuationAmplitudeFunction
  StandardFluctuationAmplitudeFunctions
  )

#INCLUDE_DIRECTORIES(${XERCESC_INCLUDE_DIR})