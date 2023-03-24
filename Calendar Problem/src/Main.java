import java.util.List;

public class Main {
    public static void main(String[] args) {

        //initialize the two calendars
        //!! time should have format HH:mm
        Calendar calendar1 = new Calendar(List.of(List.of("09:00","10:30"), List.of("12:00","13:00"),
                List.of("16:00","18:00")), List.of("09:00", "20:00"));
        Calendar calendar2 = new Calendar(List.of(List.of("10:00","11:30"), List.of("12:30","14:30"),
                List.of("14:30","15:00"), List.of("16:00","17:00")), List.of("10:00", "18:30"));

        //initialize the service class
        Service service = new Service(calendar1, calendar2,30);

        //print the result
        System.out.println(service.getAvailableMeetingSlots());
    }
}