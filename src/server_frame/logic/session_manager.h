#ifndef _LOGIC_SESSION_MANAGER_H_
#define _LOGIC_SESSION_MANAGER_H_

#pragma once

#include <design_pattern/singleton.h>

#include <utility/environment_helper.h>
#include <data/session.h>


class session_manager : public util::design_pattern::singleton<session_manager> {
public:
    typedef session::ptr_t sess_ptr_t;
    typedef UTIL_ENV_AUTO_MAP(session::key_t, sess_ptr_t, session::compare_callback) session_index_t;
    
public:
    int init();

    int proc();

    const sess_ptr_t find(const session::key_t& key) const ;
    sess_ptr_t find(const session::key_t& key);

    sess_ptr_t create(const session::key_t& key);

    void remove(const session::key_t& key, bool kickoff = false);
    void remove(sess_ptr_t sess, bool kickoff = false);

    void remove_all();

    size_t size() const;
private:
    
    session_index_t all_sessions_;
};

#endif