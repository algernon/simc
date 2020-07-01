// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================
#ifndef ITEM_EFFECT_HPP
#define ITEM_EFFECT_HPP

#include "util/span.hpp"

#include "client_data.hpp"

struct item_effect_t
{
  unsigned id;
  unsigned spell_id;
  unsigned item_id;
  int8_t   index;
  int8_t   type;
  int16_t  cooldown_group;
  int      cooldown_duration;
  int      cooldown_group_duration;

  static const item_effect_t& find( unsigned id, bool ptr );

  static util::span<const item_effect_t> find_for_item( unsigned item_id, bool ptr )
  { return dbc::find_many<item_effect_t>( item_id, ptr, {}, &item_effect_t::item_id ); }

  static const item_effect_t& nil()
  { return dbc::nil<item_effect_t>; }

  static util::span<const item_effect_t> data( bool ptr );
};

#endif /* ITEM_EFFECT_HPP */
