#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for a print job
typedef struct PrintJob {
    char user_id[20];
    char document_name[50];
    int num_pages;
    time_t submission_time;
    int priority;
    struct PrintJob* next;
} PrintJob;

// Structure for the print queue
typedef struct queue {
    PrintJob* front;
    PrintJob* rear;
    int size;
} queue;

// Function to create a new print job
PrintJob* create_job(char* user_id, char* document_name, int num_pages, int priority) {
    PrintJob* new_job = (PrintJob*)malloc(sizeof(PrintJob));
    strcpy(new_job->user_id, user_id);
    strcpy(new_job->document_name, document_name);
    new_job->num_pages = num_pages;
    new_job->submission_time = time(NULL);
    new_job->priority = priority;
    new_job->next = NULL;
    return new_job;
}

// Function to initialize a print queue
void init_queue(queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// Function to add a job to the queue
void add_job(queue* q, PrintJob* job) {
    if (job->priority) {
        // High-priority jobs go to the front
        job->next = q->front;
        q->front = job;
        if (q->rear == NULL) {
            q->rear = job;
        }
    } else {
        // Normal jobs go to the back
        if (q->rear == NULL) {
            q->front = q->rear = job;
        } else {
            q->rear->next = job;
            q->rear = job;
        }
    }
    q->size++;
    printf("Job added: %s (Priority: %s)\n", job->document_name, job->priority ? "High" : "Normal");
}

// Function to process the job at the front of the queue
PrintJob* process_job(queue* q) {
    if (q->front == NULL) {
        printf("No jobs in the queue.\n");
        return NULL;
    }
    PrintJob* job = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
    printf("Processing job: %s\n", job->document_name);
    return job;
}

// Function to display all jobs in the queue
void display_queue(queue* q) {
    if (q->front == NULL) {
        printf("No jobs in the queue.\n");
        return;
    }
    printf("Current print queue:\n");
    PrintJob* current = q->front;
    while (current != NULL) {
        printf("User: %s, Document: %s, Pages: %d, Priority: %s\n", 
               current->user_id, current->document_name, current->num_pages, 
               current->priority ? "High" : "Normal");
        current = current->next;
    }
}

// Function to remove a specific job from the queue
void remove_job(queue* q, char* user_id, char* document_name) {
    if (q->front == NULL) {
        printf("No jobs in the queue.\n");
        return;
    }

    PrintJob* current = q->front;
    PrintJob* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->user_id, user_id) == 0 && strcmp(current->document_name, document_name) == 0) {
            if (previous == NULL) {
                q->front = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == q->rear) {
                q->rear = previous;
            }

            q->size--;
            printf("Removed job: %s\n", document_name);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Job not found.\n");
}

// Function to check the queue status
int queue_status(queue* q) {
    printf("Total jobs in queue: %d\n", q->size);
    return q->size;
}

// Main function to demonstrate usage
int main() {
    queue q;
    init_queue(&q);

    int choice;
    char user_id[20];
    char document_name[50];
    int num_pages;
    int priority;

    do {
        printf("\nPrint Queue Menu:\n");
        printf("1. Add a job\n");
        printf("2. Remove a job\n");
        printf("3. Process a job\n");
        printf("4. Display queue\n");
        printf("5. Check queue status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter user ID: ");
                scanf("%19s", user_id);

                printf("Enter document name: ");
                scanf(" %49[^\n]", document_name);  // Read a line with spaces

                printf("Enter number of pages: ");
                scanf("%d", &num_pages);

                printf("Enter priority (0 for normal, 1 for high): ");
                scanf("%d", &priority);

                PrintJob* job = create_job(user_id, document_name, num_pages, priority);
                add_job(&q, job);
                break;

            case 2:
                printf("Enter user ID of job to remove: ");
                scanf("%19s", user_id);

                printf("Enter document name of job to remove: ");
                scanf(" %49[^\n]", document_name);  // Read a line with spaces

                remove_job(&q, user_id, document_name);
                break;

            case 3:
                process_job(&q);
                break;

            case 4:
                display_queue(&q);
                break;

            case 5:
                queue_status(&q);
                break;

            case 6:
                printf("You have been exited... Now run again.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    // Free remaining jobs in the queue before exiting
    while (q.front != NULL) {
        PrintJob* job = process_job(&q);
        free(job);
    }

    return 0;
}
