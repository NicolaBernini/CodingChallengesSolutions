
object Solution {

    def dist(x0: Int, y0: Int, x1: Int, y1: Int): Double = 
    {
        return scala.math.sqrt(scala.math.pow(x0-x1,2) + scala.math.pow(y0-y1,2)).asInstanceOf[Double]
    }

    def main(args: Array[String]) {
        val n: Int = scala.io.StdIn.readLine.toInt; 

        val Array(x00, y00) = scala.io.StdIn.readLine.split(" ").map(_.toInt)
        
        var x0 = x00
        var y0 = y00
        var res: Double = 0
        for(i <- 2 to n)
        {
            val Array(x1, y1) = scala.io.StdIn.readLine.split(" ").map(_.toInt)
            res = res + dist(x0, y0, x1, y1)
            x0 = x1
            y0 = y1
        }
        res = res + dist(x0,y0,x00,y00)

        println(res)
    }
}



