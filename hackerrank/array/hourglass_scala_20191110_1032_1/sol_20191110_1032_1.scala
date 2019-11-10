import java.io._
import java.math._
import java.security._
import java.text._
import java.util._
import java.util.concurrent._
import java.util.function._
import java.util.regex._
import java.util.stream._

object Solution {

    // Complete the hourglassSum function below.
    def hourglassSum(arr: Array[Array[Int]]): Int = {
        var res: Int = Int.MinValue; 
        for(i <- 0 until arr.length-2)
        {
            for (j <- 0 until arr(i).length-2)
            {
                var temp: Int=0; 
                temp += arr(i)(j) + arr(i)(j+1) + arr(i)(j+2); 
                temp += arr(i+1)(j+1); 
                temp += arr(i+2)(j) + arr(i+2)(j+1) + arr(i+2)(j+2); 
                if(temp > res) { res=temp; }
            }
        }
        return res; 
    }

    def main(args: Array[String]) {
        val stdin = scala.io.StdIn

        val printWriter = new PrintWriter(sys.env("OUTPUT_PATH"))

        val arr = Array.ofDim[Int](6, 6)

        for (i <- 0 until 6) {
            arr(i) = stdin.readLine.split(" ").map(_.trim.toInt)
        }

        val result = hourglassSum(arr)

        printWriter.println(result)

        printWriter.close()
    }
}

