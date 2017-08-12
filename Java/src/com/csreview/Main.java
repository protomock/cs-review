package com.csreview;

public class Main {

    public static void main(String[] args) {
        Thread task = new TheTask();
        synchronized (task) {
            task.start();

            try {
                task.wait();
            } catch (InterruptedException e) {
                //interrupted
            }
        }
    }
}
