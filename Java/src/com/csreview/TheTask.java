package com.csreview;

public class TheTask extends Thread {
    public void run() {
        synchronized( this ) {
            // do something here
            this.notify();
        }    
    }
}