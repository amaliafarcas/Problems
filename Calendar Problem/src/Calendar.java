import java.util.ArrayList;
import java.util.List;

public class Calendar {
    //list of booked slots (which is a list)
    List<List<String>> booked = new ArrayList<>();
    //list of range limits
    List<String> rangeLimit = new ArrayList<>();


    //constructor
    public Calendar(List<List<String>> booked, List<String> rangeLimit) {
        this.booked = booked;
        this.rangeLimit = rangeLimit;
    }

    //getters and setters
    public List<List<String>> getBooked() {
        return booked;
    }

    public void setBooked(List<List<String>> booked) {
        this.booked = booked;
    }

    public List<String> getRangeLimit() {
        return rangeLimit;
    }

    public void setRangeLimit(List<String> rangeLimit) {
        this.rangeLimit = rangeLimit;
    }

    //to string
    @Override
    public String toString() {
        return "Calendar{" +
                "booked=" + booked +
                ", rangeLimit=" + rangeLimit +
                '}';
    }
}
