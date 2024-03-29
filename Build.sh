#!bin/bash 
cd binary && ./print ascii_art
echo "You can confirm if you want to set up for your system by typing 'yes' or 'no'"
read response
if [ "$response" != "yes" ]; then
    echo "Operation cancelled"
    return 
fi

cd binary 
sudo mv get ftell rmf socket print /usr/local/bin
