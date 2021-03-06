#pragma once
#include "io_utils.hpp"

namespace hwo {
    enum class GameMode {
        STANDARD = 0, TAIKO, CTB, MANIA
    };

    struct ReplayFrame {
        int64_t time;
        float x, y;
        uint32_t keys;

        ReplayFrame();
        ReplayFrame(const std::string& string, int64_t last_frame_time);
    };

    struct ReplayData {
        std::vector<ReplayFrame> frames;
    };

    struct OsrFile {
        GameMode mode;
        io::binary_int version;
        std::string mapMd5, playerName, replayMd5;
        io::binary_short no_300s, no_100s, no_50s, no_gekis, no_katus, no_misses;
        io::binary_int score;
        io::binary_short maxCombo;
        io::binary_byte fullCombo;
        io::binary_int mods;
        std::string lifeBar;
        io::binary_long timestamp;
        ReplayData replayData;
        io::binary_long scoreID;
        io::binary_double additionalModInfo;
        int32_t replaySeed;

        OsrFile(const fs::path& path);
    };
}