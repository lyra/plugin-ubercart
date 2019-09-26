<?php
/**
 * Copyright © Lyra Network.
 * This file is part of PayZen for Ubercart. See COPYING.md for license details.
 *
 * @author    Lyra Network <https://www.lyra.com>
 * @copyright Lyra Network
 * @license   http://www.gnu.org/licenses/old-licenses/gpl-2.0.html GNU General Public License (GPL v2)
 */

/**
 * Payment gateway utilities class.
 */
class PayzenTools
{
    private static $gateway_code = 'PayZen';
    private static $gateway_name = 'PayZen';
    private static $backoffice_name = 'PayZen';
    private static $gateway_url = 'https://secure.payzen.eu/vads-payment/';
    private static $site_id = '12345678';
    private static $key_test = '1111111111111111';
    private static $key_prod = '2222222222222222';
    private static $ctx_mode = 'TEST';
    private static $sign_algo = 'SHA-256';
    private static $language = 'fr';

    private static $cms_identifier = 'Ubercart_7.x-3.x';
    private static $support_email = 'support@payzen.eu';
    private static $plugin_version = '2.1.0';
    private static $gateway_version = 'V2';

    /**
     *
     * @var array A global var to easily enable/disable features.
     */
    private static $pluginFeatures = array(
        'qualif' => false,
        'prodfaq' => true,
        'restrictmulti' => false,
        'shatwo' => true,
        'multi' => true
    );

    public static function get($field)
    {
        if (!isset(self::$$field)) {
            return null;
        }

        return self::$$field;
    }

    public static function getFeature($feature)
    {
        if (!isset(self::$pluginFeatures[$feature])) {
            return false;
        }

        return self::$pluginFeatures[$feature];
    }

    public static function getDocPattern()
    {
        $version = self::get('plugin_version');
        $minor = substr($version, 0, strrpos($version, '.'));

        return self::get('gateway_code') . '_' . self::get('cms_identifier') . '_v' . $minor . '*.pdf';
    }
}
