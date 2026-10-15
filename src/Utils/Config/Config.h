#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Config {

    enum class LogLevel { Trace, Debug, Info, Warn, Error };

    struct ManifestTimeouts {
        uint32_t resolve = 5000;
        uint32_t connect = 5000;
        uint32_t send    = 10000;
        uint32_t recv    = 10000;
    };

    struct ProxySettings {
        std::string url;
        std::string bypass;
    };

    struct SteamUiHookSettings {
        bool enabled = true;
        bool captureGetAppById = true;
        bool captureMarkAppChange = true;
        bool hookFillInAppOverview = true;
        bool hookBuildCompleteAppOverviewChange = true;
        bool hookRunFrame = true;
    };

    struct InjectionSettings {
        bool enabled = false;
        std::string libraryX86;
        std::string libraryX64;
    };

    struct CloudSettings {
        bool enabled = false;
        std::string library;
    };

    struct LoadResult {
        bool applied = false;
        bool luaPathsChanged = false;
    };

    LoadResult Load(const std::string& configPath);

    ManifestTimeouts GetManifestTimeouts();
    LogLevel GetLogLevel();
    std::string GetLogDir();
    std::vector<std::string> GetLuaPaths();
    std::string GetRemoteUrlTemplate();
    ProxySettings GetProxySettings();
    SteamUiHookSettings GetSteamUiHookSettings();
    InjectionSettings GetInjectionSettings();
    CloudSettings GetCloudSettings();
    bool GetStatsEnableApi();

    // [manifest] — provider selection lives in ManifestClient (table-driven).
    inline uint32_t manifestTimeoutResolve = 5000;
    inline uint32_t manifestTimeoutConnect = 5000;
    inline uint32_t manifestTimeoutSend    = 10000;
    inline uint32_t manifestTimeoutRecv    = 10000;

    // [log]
    inline LogLevel logLevel = LogLevel::Debug;

    // derived from configPath: <steam>/opensteamtool/
    inline std::string logDir;

    // [lua]
    inline std::vector<std::string> luaPaths;

    // [remote]
    inline std::string remoteUrlTemplate;

    // [proxy] - optional proxy for OpenSteamTool outbound HTTP requests.
    inline std::string proxyUrl;
    inline std::string proxyBypass;

    // [steamui] - startup-only SteamUI hook controls used for safe isolation.
    inline bool steamUiEnabled = true;
    inline bool steamUiCaptureGetAppById = true;
    inline bool steamUiCaptureMarkAppChange = true;
    inline bool steamUiHookFillInAppOverview = true;
    inline bool steamUiHookBuildCompleteAppOverviewChange = true;
    inline bool steamUiHookRunFrame = true;

    // [stats]
    inline bool statsEnableApi = true;

    // [inject] - optional library injection into game processes.
    inline bool injectEnabled = false;
    inline std::string injectLibraryX86;
    inline std::string injectLibraryX64;

    // [cloud] - optional Steam Cloud save redirection via CloudRedirect.
    inline bool cloudEnabled = false;
    inline std::string cloudLibrary;

}
