#pragma once

using namespace std;

class AudioManager {
private:

    ma_engine engine;

    // Guardamos todos los sonidos cargados
    vector<ma_sound*> sonidos;

public:

    AudioManager() {

        if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
            cout << "Error iniciando audio.\n";
        }
    }

    ~AudioManager() {

        // Liberar sonidos
        for (auto s : sonidos) {
            ma_sound_uninit(s);
            delete s;
        }

        ma_engine_uninit(&engine);
    }

    // ============================
    // Cargar sonido
    // ============================
    ma_sound* cargarSonido(string ruta, bool loop = false) {

        ma_sound* sonido = new ma_sound;

        if (ma_sound_init_from_file(
            &engine,
            ruta.c_str(),
            0,
            NULL,
            NULL,
            sonido
        ) != MA_SUCCESS) {

            cout << "No se pudo cargar: " << ruta << endl;
            delete sonido;
            return nullptr;
        }

        ma_sound_set_looping(sonido, loop);

        sonidos.push_back(sonido);

        return sonido;
    }

    // ============================
    // Reproducir
    // ============================
    void reproducir(ma_sound* sonido) {

        if (sonido == nullptr) return;

        ma_sound_start(sonido);
    }

    // ============================
    // Detener
    // ============================
    void detener(ma_sound* sonido) {

        if (sonido == nullptr) return;

        ma_sound_stop(sonido);
    }

    // ============================
    // Reiniciar
    // ============================
    void reiniciar(ma_sound* sonido) {

        if (sonido == nullptr) return;

        ma_sound_seek_to_pcm_frame(sonido, 0);
    }

    // ============================
    // Volumen
    // ============================
    void setVolumen(ma_sound* sonido, float volumen) {

        if (sonido == nullptr) return;

        ma_sound_set_volume(sonido, volumen);
    }
};