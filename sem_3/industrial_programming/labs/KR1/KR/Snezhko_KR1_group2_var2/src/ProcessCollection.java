import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

public class ProcessCollection {
    public static ArrayList<Employee> getListByDecreaseSalary(ArrayList<Employee> array) {
        array.sort((x,y) -> Integer.compare(y.calculateSalary(), x.calculateSalary()));
        return array;
    }
    public static ArrayList<Employee> getListBySalaryAndJobCoeff(ArrayList<Employee> array) {
        array.sort((x,y) -> Double.compare(
                (double)x.calculateSalary()/x.getJobCoefficient(),
                (double)y.calculateSalary()/y.getJobCoefficient())
        );
        return array;
    }
    public static Set<String> findOrganizationStartWithB(ArrayList<Employee> array) {
        Set<String> result = new HashSet<>();
        array.stream().filter(x -> x.getOrganization().startsWith("B")).
                forEach(x -> result.add(x.getOrganization()));
        return result;
    }
    public static Double calculateAverageSalary(ArrayList<Employee> allEmployeers, String organzation) {
        return allEmployeers.stream()
                .filter(x -> x.getOrganization().equals(organzation))
                .mapToInt(x -> x.calculateSalary())
                .average().getAsDouble();
    }
}
