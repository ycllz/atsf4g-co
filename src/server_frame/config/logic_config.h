//
// Created by owt50 on 2016/9/23.
//

#ifndef _CONFIG_LOGIC_CONFIG_H
#define _CONFIG_LOGIC_CONFIG_H

#pragma once

#include <design_pattern/singleton.h>
#include <ini_loader.h>

class logic_config : public util::design_pattern::singleton<logic_config> {
public:
    struct LC_DBCONN {
        std::string url;
        std::string host;
        uint16_t port;
    };

    struct LC_DBCONF {
        std::vector<LC_DBCONN> cluster_default;
        std::vector<LC_DBCONN> single_default;
        std::string m_strDBScriptFile[moyo_no1::EnDBScriptShaType_ARRAYSIZE];
        time_t time_retry_sec;
        time_t time_retry_usec;
        time_t timeout;
        uint64_t proc;
    };

    struct LC_LOGIC {
        uint32_t zone_id;
        uint32_t zone_step;

        time_t server_open_time;
        std::string server_resource_dir;
        bool server_maintenance_mode;

        time_t task_nomsg_timeout;
        time_t task_csmsg_timeout;
        time_t task_paymsg_timeout;
        size_t task_stack_size;

        uint32_t player_max_online_number;
        std::string player_default_openid;
        // 定时任务-自动保存间隔
        time_t player_auto_save_interval;
        time_t player_login_code_protect;
        size_t player_auto_save_limit;
        // 定时任务-缓存有效期
        time_t player_cache_expire_time;
        uint32_t player_cache_max_retry_times;
        // 登入码的有效期
        int player_login_code_valid_sec;
        time_t player_login_ban_time;
        time_t player_session_tick_sec;

        // 心跳
        time_t heartbeat_interval;
        time_t heartbeat_tolerance;
        size_t heartbeat_error_times;
        uint32_t heartbeat_ban_error_times;
        time_t heartbeat_ban_time_bound;
    };

    // ================== server configures =====================
    struct LC_LOGINSVR
    {
        time_t gmsvr_timeout_sec;
        std::string version_cfg_file;
        std::string strategy_cfg_file;
        std::string cdn_url;

        std::vector<std::string> gamesvr_list;
        time_t start_time;
        time_t end_time;

        time_t relogin_expired_time;

        std::vector<std::string> white_openid_list;
        uint32_t debug_platform_mode;
        uint32_t reload_version;
    };

    struct LC_GAMESVR {
    };
protected:
    logic_config();
    ~logic_config();

public:
    int init();

    int reload();

    uint64_t get_self_bus_id() const;

    const util::config::ini_loader& get_cfg_loader() const;
    util::config::ini_loader& get_cfg_loader();

private:
    void _load_logic(util::config::ini_loader& loader);
    void _load_limit(util::config::ini_loader& loader);
    void _load_service(util::config::ini_loader& loader);

    void _load_db(util::config::ini_loader& loader);
    void _load_db_hosts(util::config::ini_loader& loader);

    void _load_loginsvr(util::config::ini_loader& loader);
    void _load_gamesvr(util::config::ini_loader& loader);

private:
    uint64_t bus_id_;
    LC_LOGIC cfg_logic_;
    LC_DBCONF cfg_db_;

    LC_LOGINSVR cfg_loginsvr_;
    LC_GAMESVR cfg_gamesvr_;
};


#endif //ATF4G_CO_LOGIC_CONFIG_H