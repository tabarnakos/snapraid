# SnapRAID INSTALL

## Using pre-compiled binaries

Precompiled binaries for the latest stable release are available for 
the Windows platform in either 64-bits or 32-bits from the 
[SnapRAID](http://www.snapraid.it/download) website


## Installing from source

### Using the tar.gz release

Step 1: Download the source code from the 
[SnapRAID](http://www.snapraid.it/download) website 
and unpack it with:


```bash
tar xf snapraid-*.tar.gz
cd snapraid-*
```

Step 2: Configure and build SnapRAID:

```bash
./configure
make
```
Step 3: Check for correctness of the application:

```bash
make check
```

Step 4: If it terminates with "Success", you can install the application and
the documentation running as root:


```bash
sudo make install
```

### Using git

Step 1: Clone the repository and checkout the latest version:

``` git
git clone https://github.com/amadvance/snapraid.git
git checkout release/stable
```


Step 2: Generate the build configuration script :

```bash
sh autogen.sh
```

Now that the build configuration script is generated,
continue from step #2 of the install from tar.gz source package.

## After installation

To start using SnapRAID you have to change the example configuration
file snapraid.conf.example to fit your needs and copy it in /etc/snapraid.conf

To get more help, see the "Getting Started" section in the snapraid manpage
typing:

    man snapraid
    
