#include <catch2/catch.hpp>
#include <sstream>
#include "adm/document.hpp"
#include "adm/elements/audio_track_uid.hpp"
#include "adm/parse.hpp"
#include "adm/errors.hpp"

TEST_CASE("xml_parser/audio_track_uid") {
  using namespace adm;
  auto document = parseXml("xml_parser/audio_track_uid.xml");
  auto audioTrackUids = document->getElements<AudioTrackUid>();
  auto audioTrackUid = *audioTrackUids.begin();

  REQUIRE(audioTrackUid->has<AudioTrackUidId>() == true);
  REQUIRE(audioTrackUid->has<SampleRate>() == true);
  REQUIRE(audioTrackUid->has<BitDepth>() == true);

  REQUIRE(audioTrackUid->get<AudioTrackUidId>().get<AudioTrackUidIdValue>() ==
          0x00000001u);
  REQUIRE(audioTrackUid->get<SampleRate>() == 48000u);
  REQUIRE(audioTrackUid->get<BitDepth>() == 24u);
}

TEST_CASE("xml_parser/audio_track_uid_duplicate_id") {
  REQUIRE_THROWS_AS(
      adm::parseXml("xml_parser/audio_track_uid_duplicate_id.xml"),
      adm::error::XmlParsingDuplicateId);
}
