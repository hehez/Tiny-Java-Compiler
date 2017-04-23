/*
 * Syntax error test 19 (grad only): 
 * Line 13:  missing '(' in a for stmt
 *
 */
public class Err19
{
    public static void main( String[] args )
    {
	int   i      = 0;
	int   sum    = 0;

	for i = 0; i < 5; i++ )
  	  sum = sum + i;
	return;
    }
}
