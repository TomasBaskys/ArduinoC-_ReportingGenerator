using System;
using System.IO.Ports;

namespace ClicksImpressionsGenerator
{
    class Program
    {
        private readonly SerialPort _serialPort = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);

        static void Main()
        {
            new Program();
        }

        private Program()
        {
            _serialPort.DataReceived += SerialPort_DataReceived;
            _serialPort.Open();

            Console.Read();
        }

        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            Console.Write(_serialPort.ReadExisting());
        }
    }
}