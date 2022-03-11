#include "bookingsystem.h"

#include <iostream>
#include <assert.h>     /* assert */
#include <cstring>

using namespace std;


/* ===================================================
    TODO: Complete the general constructor
          update SN (using id),
          numEvent, numTicket should be initialized to their assigned values
          numPerson should be initialized to 0
   =================================================== */ 
BookingSystem::BookingSystem(int id, int nEvent, int nTicket) : SN(id), numEvent(nEvent), numTicket(nTicket), numPerson(0)
{
    // TODO: Allocate memory for events, tickets and persons here.
    for (int i=0; i<numEvent; i++) 
        events[i] = new Event(i+1);
    
    for (int i=0; i<numTicket; i++)
        tickets[i] = new Ticket(i+1);
    

    // Finish constructing with printing.
    cout <<"#"<< SN<< " BookingSystem Constructed!" << endl;
}


/* ===================================================
    TODO: Complete the copy constructor
          Deep copy all data members of another booking system
    HINT: When copying Persons, remember to first copy the event and ticket the person owns!
    HINT: Usage of a Ternary operator:
          (condition) ? (value_if_true) : (value_if_false);
   =================================================== */ 
BookingSystem::BookingSystem(const BookingSystem &other)
{
    // TODO: Clone Events.
    numEvent = other.numEvent;
    for (int i=0; i<numEvent; i++) 
        // (other.events[i]) ? (this->events[i]=new Event(*other.events[i])) : (events[i]=nullptr);
        events[i] = new Event(*other.events[i]);
        

    // TODO: Clone Tickets.
    numTicket = other.numTicket;
	for (int i=0; i<numTicket; i++) 
        // (other.tickets[i]) ? (this->tickets[i]=new Ticket(*other.tickets[i])) : (tickets[i]=nullptr);
        tickets[i] = new Ticket(*other.tickets[i]);

        
    
    // TODO: Clone Persons. We need to first copy the event and ticket the person owns
    numPerson = other.numPerson;
    for (int i=0; i<numPerson; i++) {

        Event *tempE = (other.persons[i]->event) ? (new Event(*other.persons[i]->event)) : (nullptr);
        Ticket *tempT = (other.persons[i]->ticket) ? (new Ticket(*other.persons[i]->ticket)) : (nullptr);
        persons[i] = new Person(*other.persons[i], tempE, tempT);

    }
    
    // Finish copying with printing.
    cout <<"#"<< other.SN<< " BookingSystem is Copied as ";
}

/* ===================================================
    TODO: Complete the Delegating constructor.
          Here we assume to allocate same capacity for event, ticket and person.
          Try to add only one extra line of code!
    HINT: Reuse the conversion constuctor we define above.
   =================================================== */ 
BookingSystem::BookingSystem(int id, int capacity) : BookingSystem::BookingSystem(id, capacity, capacity)
{
    // Finish constructing with printing.
    cout << "By using the Delegating constructor!" << endl;
}

/* ===================================================
    TODO: Complete the Delegating constructor.
          Here we want copy the booking system but assign different id!
    HINT: Reuse the copy constuctor we define above.
   =================================================== */ 
BookingSystem::BookingSystem(int id, const BookingSystem &other) : BookingSystem::BookingSystem(other)
{
    // TODO: Update the SN with the given id
    SN = id;

    // Finish constructing with printing.
    cout << "#" << SN << " BookingSystem!" << endl;
}


/* ===================================================
    TODO: Complete the destructor
   =================================================== */ 
BookingSystem::~BookingSystem()
{
    // TODO: Destruct Events.
    for (int i=0; i<numEvent; i++) {
        if (events[i]!=nullptr) {
            delete events[i];
            events[i]=nullptr;
        }
    } 
        

    // TODO: Destruct Tickets.
    for (int i=0; i<numTicket; i++) {
        if (tickets[i]!=nullptr) {
            delete tickets[i];
            tickets[i]=nullptr;
        }
    }
        

    // TODO: Destruct Persons.
    for (int i=0; i<numPerson; i++) {
        if (persons[i]!=nullptr) {
            delete persons[i];
            persons[i]=nullptr;
        }
    }
    
    
    // Finish destructing with printing.
    cout <<"#"<< SN<< " BookingSystem is Destructed." << endl;
}

void BookingSystem::makeBooking(const char* name)
{
    assert (!(numPerson >= maxNumPerson) && "Error: Capacity Lack");
    assert (!(numEvent < 1 || numTicket < 1) && "Error: no enough facilities for booking");
    assert (!(events[numEvent-1] == nullptr) && "Error: fake (not initialized) event or ticket");
    
    /* ===================================================
        TODO: accept person's booking by allocating a Person object. 
        The person would like to reserve an event and a ticket.
        The ownership of the latest event and ticket is then transferred to the Person object,
        which means the Event object and the Ticket object are now pointed by the new Person object instead.
    =================================================== */
    Person* person = new Person(name, events[numEvent-1], tickets[numTicket-1]);
    persons[numPerson++] = person;
    numEvent--;
    numTicket--;

    // Finish processing.
    cout <<"Booking is successful!!!" << endl;
}

///
/// Helper functions
///

void BookingSystem::releaseEvent(const char* name)
{
    assert (!(numEvent >= maxNumEvent) && "Error: Too many events, release failed.");
    assert (!(findIndexByName(name) == -1) && "Error: Cannot find the person!");

    Event* event = persons[findIndexByName(name)]->DropEvent();
    assert (!(event == nullptr) && "Error: Drop empty event.");
    
    events[numEvent++] = event;
}

void BookingSystem::releaseTicket(const char* name)
{
    assert (!(numTicket >= maxNumTicket) && "Error: Too many tickets, release failed.");
    assert (!(findIndexByName(name) == -1) && "Error: Cannot find the person!");

    Ticket* ticket = persons[findIndexByName(name)]->DropTicket();
    assert (!(ticket == nullptr) && "Error: Drop empty ticket.");

    tickets[numTicket++] = ticket;
}

void BookingSystem::log() const
{
    cout << "----------------------" << endl;
    cout << "| Booking System Log |" << endl;
    cout << "----------------------" << endl;
    cout <<"#"<< SN<< " booking system has..." << endl;
    cout << "Event: " << numEvent << "/" << maxNumEvent << endl;
    cout << "Ticket: " << numTicket << "/" << maxNumTicket << endl;
    cout << "Person: " << numPerson << "/" << maxNumPerson << endl;
}

int BookingSystem::findIndexByName(const char* name) {
    // loop to the end of the person array to find the target person by name
    for (int i = 0; i < numPerson; i++) {
        if (strcmp(persons[i]->name, name) == 0) {
            // when strcmp return 0, it means that two C strings are equal
            return i;
        }
    }
    return -1;
}
