namespace ConsoleApplication 
{
    public class Account 
    {
        int userNumber { get; set;}
        string userFirstName { get; set;}
        string userLastName { get; set;}
        double userBalance {get; set;}

        bool deposit(double amount) 
        {
            double newBalance;
            if(amount < 0.0) 
            {
                return false;
            } else {
                lock(this) {
                    newBalance = userBalance + amount;
                    userBalance = newBalance;
                }
                return true;
            }
        }

        bool withdraw(double amount) 
        {
            double newBalance;
            if(amount < 0.0) 
            {
                return false;
            } else {
                lock(this) {
                    newBalance = userBalance - amount;
                    userBalance = newBalance;
                }
                return true;
            }
        }
    }
}