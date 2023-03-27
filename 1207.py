def translate_use_google_translator(text, source_language, target_language):
    """Translate text using Google Translator.

    :param text: Text to translate.
    :param source_language: Source language.
    :param target_language: Target language.
    :return: Translated text.
    """
    translator = Translator()
    return translator.translate(text, src=source_language, dest=target_language).text
