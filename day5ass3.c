#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Song {
    char song_name[100];  
    struct Song* next;    
};


struct Song* create_song(const char* name) {
    struct Song* new_song = (struct Song*)malloc(sizeof(struct Song));
    strcpy(new_song->song_name, name);
    new_song->next = NULL; 
    return new_song;
}


void add_song(struct Song** head, const char* name) {
    struct Song* new_song = create_song(name);
    if (*head == NULL) {
        
        *head = new_song;
        new_song->next = *head;  
    } else {
        struct Song* temp = *head;
        
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new_song; 
        new_song->next = *head; 
    }
}


void display_current_song(struct Song* current) {
    if (current != NULL) {
        printf("Current Song: %s\n", current->song_name);
    } else {
        printf("No songs in the playlist.\n");
    }
}


struct Song* next_song(struct Song* current) {
    if (current != NULL) {
        return current->next;  
    }
    return NULL;
}

int main() {
    struct Song* playlist = NULL;  
    struct Song* current_song = NULL;  

   
    add_song(&playlist, "Song A");
    add_song(&playlist, "Song B");
    add_song(&playlist, "Song C");

    
    current_song = playlist;

    
    display_current_song(current_song);  
    
    current_song = next_song(current_song);  
    display_current_song(current_song);

    current_song = next_song(current_song); 
    display_current_song(current_song);

    current_song = next_song(current_song);  
    display_current_song(current_song);

    return 0;
}
