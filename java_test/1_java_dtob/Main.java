import java.io.*;

public class Main
{
	public static void main(String[] args)
	{
		String s = "";
		try
		{
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			s = in.readLine();
		}
		catch(IOException e)
		{
			
		}
		
		int num = Integer.parseInt(s);
		System.out.println(Integer.toBinaryString(num));
	}
}