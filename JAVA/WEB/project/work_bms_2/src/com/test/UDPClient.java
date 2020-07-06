package com.test;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.charset.StandardCharsets;

public class UDPClient {
    public static void main(String[] args) throws Exception {
        InetAddress addr = InetAddress.getLoopbackAddress();
        try (DatagramSocket sock = new DatagramSocket()) { // 创建DatagramSocket对象
            sock.connect(addr, 9090); // 设置要访问的服务端地址和端口
            byte[] data = "time".getBytes(StandardCharsets.UTF_8);
            DatagramPacket packet = new DatagramPacket(data, data.length); // 将字节流包装成DatagramPacket对象
            sock.send(packet); // 发送数据
            System.out.println("Data was sent.");
            Thread.sleep(1000);
            byte[] buffer = new byte[1024];
            DatagramPacket resp = new DatagramPacket(buffer, buffer.length);
            sock.receive(resp); // 接收数据
            byte[] respData = resp.getData();
            String respText = new String(respData, 0, resp.getLength(), StandardCharsets.UTF_8);
            System.out.println("Response: " + respText);
        }
    }

}
