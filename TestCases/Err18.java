/*
 * Syntax error test 18 (grad only): 
 * Line 13:  missing array subscript in an assignment (lhs)
 *
 */
public class Err18
{
    public static void main( String[] args )
    {
	int[] vector = null;
 
	vector = new int[ 10 ];
	vector[] = 11;
	return;
    }
}
