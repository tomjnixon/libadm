#include "adm/common_definitions.hpp"
#include "resources.hpp"
#include "adm/parse.hpp"

namespace adm {

  const std::map<std::string, adm::AudioPackFormatId>
  audioPackFormatLookupTable() {
    return std::map<std::string, adm::AudioPackFormatId>{
        {"0+2+0", adm::parseAudioPackFormatId("AP_00010002")},
        {"0+5+0", adm::parseAudioPackFormatId("AP_0001000c")},
        {"2+5+0", adm::parseAudioPackFormatId("AP_00010004")},
        {"4+5+0", adm::parseAudioPackFormatId("AP_00010005")},
        {"4+5+1", adm::parseAudioPackFormatId("AP_00010010")},
        {"3+7+0", adm::parseAudioPackFormatId("AP_00010007")},
        {"4+9+0", adm::parseAudioPackFormatId("AP_00010008")},
        {"9+10+3", adm::parseAudioPackFormatId("AP_00010009")},
        // {"0+7+0", adm::parseAudioPackFormatId("")},
        // {"4+7+0", adm::parseAudioPackFormatId("")},
    };
  };

  const std::map<std::string, adm::AudioTrackFormatId>
  audioTrackFormatLookupTable() {
    return std::map<std::string, adm::AudioTrackFormatId>{
        {"M+000", adm::parseAudioTrackFormatId("AT_00010003_01")},
        {"M+022", adm::parseAudioTrackFormatId("AT_00010007_01")},
        {"M-022", adm::parseAudioTrackFormatId("AT_00010008_01")},
        {"M+SC", adm::parseAudioTrackFormatId("AT_00010024_01")},
        {"M-SC", adm::parseAudioTrackFormatId("AT_00010025_01")},
        {"M+030", adm::parseAudioTrackFormatId("AT_00010001_01")},
        {"M-030", adm::parseAudioTrackFormatId("AT_00010002_01")},
        {"M+045", adm::parseAudioTrackFormatId("AT_00010026_01")},
        {"M-045", adm::parseAudioTrackFormatId("AT_00010027_01")},
        {"M+060", adm::parseAudioTrackFormatId("AT_00010018_01")},
        {"M-060", adm::parseAudioTrackFormatId("AT_00010019_01")},
        {"M+090", adm::parseAudioTrackFormatId("AT_0001000a_01")},
        {"M-090", adm::parseAudioTrackFormatId("AT_0001000b_01")},
        {"M+110", adm::parseAudioTrackFormatId("AT_00010005_01")},
        {"M-110", adm::parseAudioTrackFormatId("AT_00010006_01")},
        {"M+135", adm::parseAudioTrackFormatId("AT_0001001c_01")},
        {"M-135", adm::parseAudioTrackFormatId("AT_0001001d_01")},
        {"M+180", adm::parseAudioTrackFormatId("AT_00010009_01")},
        {"U+000", adm::parseAudioTrackFormatId("AT_0001000e_01")},
        // {"U+022", adm::parseAudioTrackFormatId("")},
        // {"U-022", adm::parseAudioTrackFormatId("")},
        {"U+030", adm::parseAudioTrackFormatId("AT_0001000d_01")},
        {"U-030", adm::parseAudioTrackFormatId("AT_0001000f_01")},
        {"U+045", adm::parseAudioTrackFormatId("AT_00010022_01")},
        {"U-045", adm::parseAudioTrackFormatId("AT_00010023_01")},
        // {"U+060", adm::parseAudioTrackFormatId("")},
        // {"U-060", adm::parseAudioTrackFormatId("")},
        {"U+090", adm::parseAudioTrackFormatId("AT_00010013_01")},
        {"U-090", adm::parseAudioTrackFormatId("AT_00010014_01")},
        {"U+110", adm::parseAudioTrackFormatId("AT_00010010_01")},
        {"U-110", adm::parseAudioTrackFormatId("AT_00010012_01")},
        {"U+135", adm::parseAudioTrackFormatId("AT_0001001e_01")},
        {"U-135", adm::parseAudioTrackFormatId("AT_0001001f_01")},
        {"U+180", adm::parseAudioTrackFormatId("AT_00010011_01")},
        {"UH+180", adm::parseAudioTrackFormatId("AT_00010028_01")},
        {"T+000", adm::parseAudioTrackFormatId("AT_0001000c_01")},
        {"B+000", adm::parseAudioTrackFormatId("AT_00010015_01")},
        // {"B+022", adm::parseAudioTrackFormatId("")},
        // {"B-022", adm::parseAudioTrackFormatId("")},
        // {"B+030", adm::parseAudioTrackFormatId("")},
        // {"B-030", adm::parseAudioTrackFormatId("")},
        {"B+045", adm::parseAudioTrackFormatId("AT_00010016_01")},
        {"B-045", adm::parseAudioTrackFormatId("AT_00010016_01")},
        // {"B+060", adm::parseAudioTrackFormatId("")},
        // {"B-060", adm::parseAudioTrackFormatId("")},
        // {"B+090", adm::parseAudioTrackFormatId("")},
        // {"B-090", adm::parseAudioTrackFormatId("")},
        // {"B+110", adm::parseAudioTrackFormatId("")},
        // {"B-110", adm::parseAudioTrackFormatId("")},
        // {"B+135", adm::parseAudioTrackFormatId("")},
        // {"B-135", adm::parseAudioTrackFormatId("")},
        // {"B+180", adm::parseAudioTrackFormatId("")},
        {"LFE1", adm::parseAudioTrackFormatId("AT_00010020_01")},
        {"LFE2", adm::parseAudioTrackFormatId("AT_00010021_01")}};
  };

  std::shared_ptr<Document> getCommonDefinitions() {
    std::stringstream commonDefinitions;
    getEmbeddedFile("common_definitions.xml", commonDefinitions);
    return parseXml(commonDefinitions,
                    xml::ParserOptions::recursive_node_search);
  }

}  // namespace adm
