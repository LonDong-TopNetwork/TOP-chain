// Copyright (c) 2022 - present Telos Foundation & contributors
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "xchain_fork/xfork_points.h"

NS_BEG2(top, fork_points)

#if defined(XCHAIN_FORKED_BY_DEFAULT)
#    if (!defined(XBUILD_CI) && !defined(XBUILD_DEV) && !defined(XBUILD_BOUNTY) && !defined(XBUILD_GALILEO))
#        error "XCHAIN_FORKED_BY_DEFAULT cannot be used in mainnet"
#    endif

optional<xfork_point_t> v1_7_0_block_fork_point     = xfork_point_t{xfork_point_type_t::logic_time, 0, "v1.7 version control"};
optional<xfork_point_t> v1_7_0_sync_point           = xfork_point_t{xfork_point_type_t::logic_time, 0, "v1.7 sync protocol fork"};

#else
optional<xfork_point_t> v1_7_0_block_fork_point     = xfork_point_t{xfork_point_type_t::logic_time, 9459720, "v1.7 version control"};
optional<xfork_point_t> v1_7_0_sync_point           = xfork_point_t{xfork_point_type_t::logic_time, 9460080, "v1.7 sync protocol fork"};

#endif

NS_END2
