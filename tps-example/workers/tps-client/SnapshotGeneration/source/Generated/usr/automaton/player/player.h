// Generated by SpatialOS codegen. DO NOT EDIT!
// source: automaton/player/player.schema
#ifndef SPATIALOS_SCHEMA_automaton_player_player_schema_14552441770541960094_INCLUDED
#define SPATIALOS_SCHEMA_automaton_player_player_schema_14552441770541960094_INCLUDED
#include <improbable/collections.h>
#include <improbable/worker.h>
#include <cstddef>
#include <cstdint>
#include <set>
#include <string>

struct Pbio;
struct Pbio_Object;

namespace automaton {
namespace player {

// Forward declarations.
//----------------------------------------------------------------

class Heartbeat;
class KilledPlayer;
class PlayerData;

namespace detail {
const ::worker::detail::ClientComponentVtable& Vtable_Player();
struct GenericCommandObject_Player {
  std::uint32_t CommandId;
  ::worker::Variant<> CommandObject;
};
}  // ::detail

// Enumerations.
//----------------------------------------------------------------

// Data classes.
//----------------------------------------------------------------

class Heartbeat {
public:
  // Main constructor.
  Heartbeat();

  // Copyable and moveable.
  Heartbeat(Heartbeat&&) = default;
  Heartbeat(const Heartbeat&) = default;
  Heartbeat& operator=(Heartbeat&&) = default;
  Heartbeat& operator=(const Heartbeat&) = default;
  ~Heartbeat() = default;

  bool operator==(const Heartbeat&) const;
  bool operator!=(const Heartbeat&) const;
};

class KilledPlayer {
public:
  // Main constructor.
  KilledPlayer();

  // Copyable and moveable.
  KilledPlayer(KilledPlayer&&) = default;
  KilledPlayer(const KilledPlayer&) = default;
  KilledPlayer& operator=(KilledPlayer&&) = default;
  KilledPlayer& operator=(const KilledPlayer&) = default;
  ~KilledPlayer() = default;

  bool operator==(const KilledPlayer&) const;
  bool operator!=(const KilledPlayer&) const;
};

class PlayerData {
public:
  // Main constructor.
  PlayerData();

  // Copyable and moveable.
  PlayerData(PlayerData&&) = default;
  PlayerData(const PlayerData&) = default;
  PlayerData& operator=(PlayerData&&) = default;
  PlayerData& operator=(const PlayerData&) = default;
  ~PlayerData() = default;

  bool operator==(const PlayerData&) const;
  bool operator!=(const PlayerData&) const;
};

// Component metaclasses and update classes.
//----------------------------------------------------------------

/**
 * This type can be supplied as the template parameter to all component-related templated types
 * and methods in the C++ worker API. For example:
 *
 *   using ::automaton::player::Player;
 *
 *   Player::Update update;
 *   connection.SendComponentUpdate< Player >(entity_id, update);
 *
 *   dispatcher.OnComponentUpdate< Player >(
 *       [&](const worker::ComponentUpdateOp< Player >& op) {
 *         worker::EntityId entity_id = op.GetEntityId();
 *         Player::Update update = op.GetUpdate();
 *       });
 *
 *   Player::Data data = entity.Get< Player >();
 */
struct Player : ::worker::detail::ComponentMetaclassBase<
    Player, ::automaton::player::detail::Vtable_Player> {
  static constexpr const ::worker::ComponentId ComponentId = 30002;
  using Data = ::automaton::player::PlayerData;
  using GenericCommandObject = ::automaton::player::detail::GenericCommandObject_Player;

  class Update {
  public:
    // Default-constructible, copyable and movable.
    Update() = default;
    Update(Update&&) = default;
    Update(const Update&) = default;
    Update& operator=(Update&&) = default;
    Update& operator=(const Update&) = default;
    ~Update() = default;

    bool operator==(const Update&) const;
    bool operator!=(const Update&) const;

    /** Creates an Update from a ::automaton::player::PlayerData object. */
    static Update FromInitialData(const ::automaton::player::PlayerData& data);

    /**
     * Converts to a ::automaton::player::PlayerData
     * object. It is an error to call this function unless *all* of the optional fields in this
     * update are filled in.
     */
    ::automaton::player::PlayerData ToInitialData() const;

    /**
     * Replaces fields in the given ::automaton::player::PlayerData
     * object with the corresponding fields in this update, where present.
     */
    void ApplyTo(::automaton::player::PlayerData&) const;

    // Event field heartbeat.
    const ::worker::List< ::automaton::player::Heartbeat >& heartbeat() const;
    ::worker::List< ::automaton::player::Heartbeat >& heartbeat();
    Update& add_heartbeat(const ::automaton::player::Heartbeat&);

    // Event field killed_player.
    const ::worker::List< ::automaton::player::KilledPlayer >& killed_player() const;
    ::worker::List< ::automaton::player::KilledPlayer >& killed_player();
    Update& add_killed_player(const ::automaton::player::KilledPlayer&);

  private:
    ::worker::List< ::automaton::player::Heartbeat > _heartbeat;
    ::worker::List< ::automaton::player::KilledPlayer > _killed_player;
  };

};

// Implementation details.
//----------------------------------------------------------------

namespace detail {

void Write_Heartbeat(const ::automaton::player::Heartbeat&, ::Pbio_Object*);

::automaton::player::Heartbeat Read_Heartbeat(::Pbio_Object*);

void Write_KilledPlayer(const ::automaton::player::KilledPlayer&, ::Pbio_Object*);

::automaton::player::KilledPlayer Read_KilledPlayer(::Pbio_Object*);

void Write_PlayerData(const ::automaton::player::PlayerData&, ::Pbio_Object*);

::automaton::player::PlayerData Read_PlayerData(::Pbio_Object*);

}  // ::detail
}  // ::player
}  // ::automaton

#endif  // SPATIALOS_SCHEMA_automaton_player_player_schema_14552441770541960094_INCLUDED
