/*
 * Syntax error test 20 (grad only): 
 * Line 13:  malformed for stmt(just asingle ident)
 *
 */
public class Err20
{
    public static void main( String[] args )
    {
	int   i      = 0;
	int   sum    = 0;

	for( i )
  	  sum = sum + i;
	return;
    }
}
