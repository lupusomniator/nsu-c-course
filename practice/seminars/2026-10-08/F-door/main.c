#include <stdio.h>
#include <door.h>
#include <door.h>

static const char *state_name(DoorState state) {
    switch (state) {
        case DOOR_CLOSED: return "closed";
        case DOOR_OPEN: return "open";
        case DOOR_LOCKED: return "locked";
    }
    return "invalid";
}

int main(void) {
    Door doors[2];
    door_init(&doors[0]);
    door_init(&doors[1]);
    int index;
    char command;
    while (scanf("%d %c", &index, &command) == 2) {
        if (index < 0 || index > 1) { return 1; }
        int accepted;
        if (command == 'i') {
            door_init(&doors[index]);
            accepted = 1;
        } else {
            DoorEvent event;
            switch (command) {
                case 'o': event = DOOR_OPEN_EVENT; break;
                case 'c': event = DOOR_CLOSE_EVENT; break;
                case 'l': event = DOOR_LOCK_EVENT; break;
                case 'u': event = DOOR_UNLOCK_EVENT; break;
                default: return 1;
            }
            accepted = door_apply(&doors[index], event);
        }
        printf("%d %s %s\n", accepted,
               state_name(door_state(&doors[0])),
               state_name(door_state(&doors[1])));
    }
    return 0;
}
