#include "map_parser.h"

std::unique_ptr<cParser> cMapParser::create() 
{ 
    return std::make_unique<cMapParser>();
}

config_storage cMapParser::parse_file(std::string strFileName)
{
    pugi::xml_document oMapfile;
    pugi::xml_parse_result result = oMapfile.load_file(strFileName.c_str());

    if (!result)
    {
        std::cerr << "XML parsing failed! Error description: " << result.description() << std::endl;
    }

    config_storage oMeasurementConfig = {};

    for(const auto& oOutputPin : oMapfile.child("mapping").child("outputs").children("output"))
    {
        const std::string strDaqEvent = oOutputPin.attribute("daq_event").as_string();
        const std::string strPollingInterval = oOutputPin.attribute("polling_interval").as_string();
        std::string strDaqPrescaller = oOutputPin.attribute("daq_prescaler").as_string();

        std::string strMethodName = {""};
        if(!strDaqEvent.empty())
        {
            if(strDaqPrescaller.empty())
            {
                strDaqPrescaller.append("1");
            }

            strMethodName.append("DAQ " + strDaqEvent + " (" + strDaqPrescaller + ")");
        }
        else
        {
            strMethodName.append("Polling " + strPollingInterval + " [ms]");
        }

        std::vector<std::string> oSignals = {};
        for(const auto& oSignal : oOutputPin.children("assignment"))
        {
            std::string strSignalName = {""};

            if(!std::string(oSignal.child_value("raw_value")).compare("true"))
            {
                strSignalName.append("raw.");
            }

            strSignalName.append(oSignal.child_value("to"));
            oSignals.push_back(strSignalName);
        }

        // if the MeasurementMethod already exists in the Config
        // we merge the signals into the existing one
        if (oMeasurementConfig.contains(strMethodName)) 
        {
            for(const auto& oSignal : oSignals)
            {
                // check if the signal alreay exists in the MeasurementMethod
                // if not add it to the Method
                std::vector<std::string> oVector = oMeasurementConfig[strMethodName];
                if(std::find(oVector.begin(), oVector.end(), oSignal) == oVector.end())
                {
                    oMeasurementConfig[strMethodName].push_back(oSignal);
                }
            }
        } 
        else 
        {
            oMeasurementConfig.insert(std::pair{strMethodName, oSignals});
        }

    }

    return oMeasurementConfig;
}
