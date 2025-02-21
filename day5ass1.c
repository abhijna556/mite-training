#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 10


char back_stack[MAX_HISTORY][100]; 
char forward_stack[MAX_HISTORY][100];  
int back_top = -1;   
int forward_top = -1; 
char current_page[100]; 


void init_browser() {
    strcpy(current_page, "");  
}


void visit_page(const char* url) {
    if (strlen(current_page) > 0) {
        back_top++; 
        strcpy(back_stack[back_top], current_page);
    }
    
    
    forward_top = -1;

    
    strcpy(current_page, url);
    printf("Visited: %s\n", url);
}


void go_back() {
    if (back_top >= 0) {
        
        forward_top++;
        strcpy(forward_stack[forward_top], current_page);


        strcpy(current_page, back_stack[back_top]);
        back_top--;
        printf("Go Back: Current Page: %s\n", current_page);
    } else {
        printf("No more history to go back to.\n");
    }
}


void go_forward() {
    if (forward_top >= 0) {
        
        back_top++;
        strcpy(back_stack[back_top], current_page);

        // Move forward to the next page
        strcpy(current_page, forward_stack[forward_top]);
        forward_top--;
        printf("Go Forward: Current Page: %s\n", current_page);
    } else {
        printf("No more history to go forward to.\n");
    }
}


void display_current_page() {
    printf("Current Page: %s\n", current_page);
}

int main() {
    init_browser();

    visit_page("google.com");
    visit_page("github.com");
    visit_page("stackoverflow.com");

    go_back(); 
    go_forward(); 

    display_current_page();  

    return 0;
}
