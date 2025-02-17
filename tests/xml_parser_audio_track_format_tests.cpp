#include <catch2/catch.hpp>
#include <sstream>
#include "adm/document.hpp"
#include "adm/elements/audio_track_format.hpp"
#include "adm/elements/frequency.hpp"
#include "adm/parse.hpp"
#include "adm/errors.hpp"

TEST_CASE("xml_parser/audio_track_format") {
  using namespace adm;
  auto document = parseXml("xml_parser/audio_track_format.xml");
  auto trackFormats = document->getElements<AudioTrackFormat>();
  auto trackFormat = *trackFormats.begin();
  REQUIRE(
      trackFormat->get<AudioTrackFormatId>().get<AudioTrackFormatIdValue>() ==
      0x0001u);
  REQUIRE(trackFormat->get<AudioTrackFormatId>().get<TypeDescriptor>() ==
          TypeDefinition::OBJECTS);
  REQUIRE(
      trackFormat->get<AudioTrackFormatId>().get<AudioTrackFormatIdCounter>() ==
      0x01u);
  REQUIRE(trackFormat->get<AudioTrackFormatName>() == "MyTrackFormat");
  REQUIRE(trackFormat->get<FormatDescriptor>() == FormatDefinition::PCM);
}

TEST_CASE("xml_parser/audio_track_format_duplicate_id") {
  REQUIRE_THROWS_AS(
      adm::parseXml("xml_parser/audio_track_format_duplicate_id.xml"),
      adm::error::XmlParsingDuplicateId);
}
