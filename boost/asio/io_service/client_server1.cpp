/**
  * @brief Modified version of Boost Asio Test Case 
  * @ref http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tutdaytime1/src.html
  * @ref http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tutdaytime2/src.html
  */
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/lexical_cast.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

int main_server(boost::asio::io_service& io_service, int in_port)
{
  try
  {
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), in_port));

    for (;;)
    {
      tcp::socket socket(io_service);
      acceptor.accept(socket);

      std::string message = make_daytime_string();

      boost::system::error_code ignored_error;
      boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

int main(int argc, char* argv[])
{
    std::string t_ip("127.0.0.1"); 
    std::string t_port("51"); 
    
  try
  {
    
    if (argc > 1)
    {
        int t_val = 0; 
        if((t_val = atoi(argv[1])) <= 0)
        {
            std::cerr << "Invalid Port" << std::endl; 
            return 1; 
        }
        t_port = boost::lexical_cast<std::string>(t_val) ; 
        std::cout << "Using port = " << t_port << std::endl; 
    }
    
    if(argc > 2)
    {
        std::cout << "Using IP " << argv[2] << std::endl; 
        t_ip = std::string(argv[2]); 
    }
    

    boost::asio::io_service io_service;
    
    boost::thread t_server(boost::bind(main_server, boost::ref(io_service), boost::lexical_cast<int>(t_port))); 

    tcp::resolver resolver(io_service);
    tcp::resolver::query query(t_ip, t_port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);

    for (int i=0; i<10; ++i)
    {
      boost::array<char, 128> buf;
      boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);

      if (error == boost::asio::error::eof)
        break; // Connection closed cleanly by peer.
      else if (error)
        throw boost::system::system_error(error); // Some other error.

      std::cout.write(buf.data(), len);
    }
    
    t_server.join(); 
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
