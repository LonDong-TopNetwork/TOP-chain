#pragma once

#include "xbasic/xmemory.hpp"
#include "xdb_util.h"
#include "xvledger/xvblockstore.h"

using top::db_export::json;

NS_BEG2(top, db_reset)

class xdb_reset_t {
public:
    xdb_reset_t(observer_ptr<base::xvblockstore_t> const & blockstore);
    ~xdb_reset_t() = default;

    void generate_property_reset_check_file(std::vector<std::string> const & accounts);
    void verify_property(json const & contract, json const & user);
    void generate_state_reset_file(std::vector<std::string> const & accounts);

private:
    void get_unit_set_property(std::vector<std::string> const & accounts_vec, json & accounts_json);
    void get_contract_stake_property_string(json & stake_json);
    void get_contract_stake_property_map_string_string(json & stake_json);
    void get_contract_table_stake_property_string(json & stake_json);
    void get_contract_table_stake_property_map_string_string(json & stake_json);
    json get_units_state(std::vector<std::string> const & accounts);
    void clear_useless_property(std::string acc, base::xvbstate_t * bstate);

    observer_ptr<base::xvblockstore_t> m_blockstore;
};

NS_END2