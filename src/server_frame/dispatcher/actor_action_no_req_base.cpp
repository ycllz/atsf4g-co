//
// Created by owt50 on 2016/11/14.
//

#include "actor_action_no_req_base.h"

#include <data/player.h>


actor_action_no_req_base::actor_action_no_req_base() { }

actor_action_no_req_base::~actor_action_no_req_base() { }

std::shared_ptr<player> actor_action_no_req_base::get_player() const {
    return player::get_global_gm_player();
}

void actor_action_no_req_base::send_rsp_msg() {
}