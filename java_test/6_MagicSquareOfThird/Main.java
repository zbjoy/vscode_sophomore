import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int[][] nums = new int[3][3];
		
		for (int i = 0; i < 9; i++)
		{
			nums[i / 3][i % 3] = s.nextInt();
		}
		
		if (isMagicSquare(nums))
		{
			System.out.print("YES");
		}
		else
		{
			System.out.print("NO");
		}
	}
	
	static boolean isMagicSquare(int[][] nums)
	{
		int reference = nums[0][0] + nums[0][1] + nums[0][2];
		for (int row = 0; row < 3; row++)
		{
			int rowsNum = 0;
			for (int col = 0; col < 3; col++)
			{
				rowsNum += nums[row][col];
			}
			
			if (rowsNum != reference)
			{
				return false;
			}
		}
		
		for (int col = 0; col < 3; col++)
		{
			int colsNum = 0;
			for (int row = 0; row < 3; row++)
			{
				colsNum += nums[row][col];
			}
			
			if (colsNum != reference)
			{
				return false;
			}
		}
		
		int row = 0;
		int col = 0;
		if (reference != nums[row++][col++] + nums[row++][col++] + nums[row][col])
		{
			return false;
		}
		
		row = 0;
		col = 2;
		if (reference != nums[row++][col--] + nums[row++][col--] + nums[row][col])
		{
			return false;
		}
		
		return true;
	}
}