
#ifndef BIONETWORKTEMPLATELIBRARY_H
#define BIONETWORKTEMPLATELIBRARY_H

#include <string>
#include <vector>
#include <map>
#include "BionetworkDLLSpecifier.h"

class BionetworkSBML;

class BIONETWORK_EXPORT BionetworkTemplateLibrary{
    private:
        //std::string typeName;
        std::string templateLibraryName;
        
        std::map<std::string, double> sbmlInitialConditions;
        //std::map<std::string, double> cc3dInitialConditions;
        //std::map<std::string, const BionetworkSBML *> intracellularModels;
        std::map<std::string, const BionetworkSBML *> bionetworkModels;
        
    public:
        BionetworkTemplateLibrary();
        ~BionetworkTemplateLibrary();
        BionetworkTemplateLibrary(std::string);
        
        //std::string getTypeName() const {return typeName;};
        //void setTypeName(std::string _cellTypeName) {typeName = _cellTypeName;};
        std::string getTemplateLibraryName() const {return templateLibraryName;};
        void setTemplateLibraryName(std::string _newTemplateLibraryName) {templateLibraryName = _newTemplateLibraryName;};
        
        std::vector<std::string> getModelNames() const ;
		std::string getModelNamesAsString() const ;
        //std::map<std::string, const BionetworkSBML *> getSBMLModels() const { return intracellularModels; };
        std::map<std::string, const BionetworkSBML *> getSBMLModels() const { return bionetworkModels; };
        bool hasSBMLModelByKey(std::string) const ;
        
        void addSBMLModel(const BionetworkSBML *);
        const BionetworkSBML *getSBMLModelByName(std::string) const ;
        const BionetworkSBML *getSBMLModelByKey(std::string) const ;
        
        //void setInitialCondition(std::string, std::string, double);
        //std::map<std::string, double> getInitialConditions(std::string) const ;
        void setInitialCondition(std::string, double);
        std::map<std::string, double> getInitialConditions() const ;
};

#endif





