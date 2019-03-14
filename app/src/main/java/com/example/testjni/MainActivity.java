package com.example.testjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("JniTest");
    }
    public native String getStringFromC();

    public native double getString2FromC(String i);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv=findViewById(R.id.tv);
        tv.setText(getStringFromC());

        TextView tv2=findViewById(R.id.tv2);
        tv2.setText(getString2FromC("29bd05ac4ba3ca3f")+"");
    }
}
