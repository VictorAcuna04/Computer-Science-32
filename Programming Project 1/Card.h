namespace cs32
{
    class Card
    {
        public:
            Card();
            Card( Suit s, Face f );
            
            std::string to_string() const;
            
            Suit getSuit() const;
            void setSuit( Suit s );
            Face getFace() const;
            void setFace( Face f );
        
            int  getValue() const;
        private:
            Suit mSuit;
            Face mFace;
    };
}
