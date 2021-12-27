/* Java program to calculate SHA-1 hash value*/
// package A3;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.*;

public class SHA {
	public static String encryptThisString(String input)
	{
		try {
			// getInstance() method is called with algorithm SHA-1
			MessageDigest md = MessageDigest.getInstance("SHA-1");

			byte[] messageDigest = md.digest(input.getBytes());

			// Convert byte array into signum representation
			BigInteger no = new BigInteger(1, messageDigest);

			// Convert message digest into hex value
			String hashtext = no.toString(16);

			// Add preceding 0s to make it 32 bit
			while (hashtext.length() < 32) {
				hashtext = "0" + hashtext;
			}

			// return the HashText
			return hashtext;
		}

		// For specifying wrong message digest algorithms
		catch (NoSuchAlgorithmException e) {
			throw new RuntimeException(e);
		}
	}

	// Driver code
	public static void main(String args[]) throws NoSuchAlgorithmException
	{
		
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter a string : ");
		String s = sc.nextLine(); 

		System.out.println("HashCode Generated by SHA-1 for: ");

		System.out.println("\n" + s + " : " + encryptThisString(s));

		
		
	}
}
/*
spartan@spartan:~/Desktop/ICS/3$ javac SHA.java 
spartan@spartan:~/Desktop/ICS/3$ java SHA 
Enter a string : parimalmahindrakar
HashCode Generated by SHA-1 for: 

parimalmahindrakar : 526fa0327306faed6a63dd89695370c53b5c5010
spartan@spartan:~/Desktop/ICS/3$ 

*/