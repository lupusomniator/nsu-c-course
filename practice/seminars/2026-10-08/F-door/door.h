#ifndef DOOR_H
#define DOOR_H

typedef enum { DOOR_CLOSED, DOOR_OPEN, DOOR_LOCKED } DoorState;
typedef enum { DOOR_OPEN_EVENT, DOOR_CLOSE_EVENT,
               DOOR_LOCK_EVENT, DOOR_UNLOCK_EVENT } DoorEvent;
typedef struct { DoorState state; } Door;

void door_init(Door *door);
int door_apply(Door *door, DoorEvent event);
DoorState door_state(const Door *door);

#endif
