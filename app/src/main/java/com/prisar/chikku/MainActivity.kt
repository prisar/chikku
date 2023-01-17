package com.prisar.chikku

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.prisar.chikku.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()

        brightness("path", 0.5F)
    }

    /**
     * A native method that is implemented by the 'chikku' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun brightness(imagePath: String?, brightness: Float)

    companion object {
        // Used to load the 'chikku' library on application startup.
        init {
            System.loadLibrary("chikku")
        }
    }
}