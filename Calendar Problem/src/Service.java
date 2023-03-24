import java.time.Duration;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Service {
    //the calendars
    Calendar calendar1;
    Calendar calendar2;

    //duration of the desired meeting between the two calendars
    int meetingDuration;

    //constructor
    public Service(Calendar calendar1, Calendar calendar2, int meetingDuration) {
        this.calendar1 = calendar1;
        this.calendar2 = calendar2;
        this.meetingDuration = meetingDuration;
    }

    //converting a slot (list of hours) into the actual time of the day; form String to LocalTime
    //List<String> stringTime - input list eg: ["09:00", "10:00"]
    //List<LocalTime> listTime - output list eg: [09:00, 10:00]
    List<LocalTime> getActualHoursOfTheDay(List<String> stringTime) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm");
        List<LocalTime> listTime = new ArrayList<>();
        for (String s : stringTime) {
            LocalTime time = LocalTime.parse(s, formatter);
            listTime.add(time);
        }
        return listTime;
    }


    //getting the available slots in a calendar
    List<List<LocalTime>> getAvailableSlots(Calendar calendar) {
        //get the calendar time range in LocalTime format
        List<LocalTime> dayRange = getActualHoursOfTheDay(calendar.getRangeLimit());
        //initialize the list of available slots
        List<List<LocalTime>> availableSlots = new ArrayList<>();
        //initialize the start variable with the start of the day
        LocalTime start = dayRange.get(0);
        //we iterate through each booked slot of the day and transform it into LocalTime
        for (List<String> bookedSlot : calendar.getBooked()) {
            List<LocalTime> currentSlot = getActualHoursOfTheDay(bookedSlot);
            //we set end variable to the start of the current slot we iterate through
            LocalTime end = currentSlot.get(0);
            //If the start time is before the start time of the booked slot (end), we add a new available slot
            // from start to the start time of the booked slot (end) to the availableSlots list.
            if (start.isBefore(end)) {
                availableSlots.add(Arrays.asList(start, end));
            }
            //we update the start variable to the end time of the current booked slot.
            start = currentSlot.get(1);
        }
        //we check if there is any remaining time between end of last slot and end of the day
        if (start.isBefore(dayRange.get(dayRange.size() - 1))) {
            availableSlots.add(Arrays.asList(start, dayRange.get(dayRange.size() - 1)));
        }
        //we return all available slots
        return availableSlots;

    }

    //we get available slots between the two calendars larger or equal to the duration of the meeting we want to set
    public List<List<String>> getAvailableMeetingSlots() {
        //lists of available slots of each of the two calendars
        List<List<LocalTime>> availableSlots1 = getAvailableSlots(calendar1);
        List<List<LocalTime>> availableSlots2 = getAvailableSlots(calendar2);
        //we initialize the available time for meeting list
        List<List<String>> availableMeetingSlots = new ArrayList<>();

        //for each available slot,
        for (List<LocalTime> slot1 : availableSlots1) {
            for (List<LocalTime> slot2 : availableSlots2) {
                //we get the start and the end time of intersection of the available slots
                LocalTime start = slot1.get(0).isAfter(slot2.get(0)) ? slot1.get(0) : slot2.get(0);
                LocalTime end = slot1.get(1).isBefore(slot2.get(1)) ? slot1.get(1) : slot2.get(1);
                //we calculate the duration of the time slot
                long duration = Duration.between(start, end).toMinutes();
                //if it fits the requirements,
                if (duration >= meetingDuration) {
                    //we add it to the list of available meeting slots (as a string)
                    availableMeetingSlots.add(Arrays.asList(start.toString(), end.toString()));
                }
            }
        }
        //we return the available meeting slots
        return availableMeetingSlots;
    }

}
