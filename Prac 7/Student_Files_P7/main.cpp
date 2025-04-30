#include "Calendar.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "This main works as follows, I will create 2 calendars called cal1 and cal2. These 2 calendars will be created using different constructor" << endl
         << "methods. I will create an event called event. Then I will display the event variable. After the event variable is displayed I will" << endl
         << "display cal2 and cal1. please not cal2 is supposed to have 4 events and cal1 is supposed to have 2 events. I will" << endl
         << "then delete the first event of cal1 and display cal1 again." << endl
         << endl
         << endl
         << endl;
    cout << "Running the program:" << endl;
    Calendar cal;
    vector<event_data> data = get_api_results(3, 4);
    cal.createEvent(data[0]);
    cal.createEvent(data[1]);
    Event event(data[3].start, data[3].end, data[3].id, data[3].type);
    cout << "This is the event variable" << endl;
    cout << event << endl;
    Calendar cal2(data);
    Event *first = cal.getFirstEvent();
    cout << "Cal 2 is as follows: " << endl;
    cout << cal2 << endl;
    cout << "cal is as follows: " << endl;
    cout << cal << endl;
    cout << "The ID of the first event is: " << first->id << endl;
    cout << "The ID of the second event is: " << first->next->id << endl;
    cout << "Removing study session" << endl;
    cal.removeEvent(first->id);
    cout << cal << endl;
    cout << "Filtering events using Class test as paramater: " << endl;
    string *type = new string("Class Test");
    vector<Event> cal2Events = cal2.filterEvents(NULL, NULL, NULL, type);
    for (int i = 0; i < cal2Events.size(); i++)
    {
        cout << cal2Events[i] << endl;
    }
    Event *Now = cal2.getFirstEvent()->next;
    cout << "Theis event is: " << endl;
    cout << *Now << endl;
    cout << "Working up until here" << endl;
    Event *nextEvent = cal2.getUpcomingEvent(cal2.getFirstEvent()->next->start);
    cout << " The next event shown is: " << endl;
    cout << *nextEvent;
}