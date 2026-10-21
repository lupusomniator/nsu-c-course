#include "door.h"

void door_init(Door *door) { door->state = DOOR_CLOSED; }

int door_apply(Door *door, DoorEvent event) {
    switch (door->state) {
        case DOOR_CLOSED:
            if (event == DOOR_OPEN_EVENT) {
                door->state = DOOR_OPEN;
                return 1;
            }
            if (event == DOOR_LOCK_EVENT) {
                door->state = DOOR_LOCKED;
                return 1;
            }
            break;
        case DOOR_OPEN:
            if (event == DOOR_CLOSE_EVENT) {
                door->state = DOOR_CLOSED;
                return 1;
            }
            break;
        case DOOR_LOCKED:
            if (event == DOOR_UNLOCK_EVENT) {
                door->state = DOOR_CLOSED;
                return 1;
            }
            break;
    }
    return 0;
}

DoorState door_state(const Door *door) { return door->state; }
