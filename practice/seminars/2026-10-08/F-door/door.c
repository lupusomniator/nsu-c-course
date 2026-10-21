#include "door.h"
void door_init(Door *door) { door->state = DOOR_CLOSED; }
int door_apply(Door *door, DoorEvent event) {
    (void)door; (void)event;
    return 0; /* TODO */
}
DoorState door_state(const Door *door) { return door->state; }
