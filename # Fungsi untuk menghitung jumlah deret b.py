# Fungsi untuk menghitung jumlah deret bilangan ganjil
def jumlah_deret_ganjil(n):
    return n * n

# Meminta input dari pengguna
n = int(input("Masukkan jumlah suku ganjil pertama (n): "))

# Menghitung dan menampilkan hasil
print(f"Jumlah dari {n} bilangan ganjil pertama adalah: {jumlah_deret_ganjil(n)}")